import os
import re
import html
import subprocess

PROJECT_DIR = r"e:\oops med proejct"
OUTPUT_HTML = os.path.join(PROJECT_DIR, "AI_Care_Box_Presentation_Report.html")
OUTPUT_PDF = os.path.join(PROJECT_DIR, "AI_Care_Box_Presentation_Report.pdf")
CHROME_PATH = r"C:\Program Files\Google\Chrome\Application\chrome.exe"

def highlight_cpp(code_text):
    # Regex for C++ tokens
    # Escape HTML first, but let's tokenize directly
    keywords = {
        'class', 'public', 'private', 'protected', 'virtual', 'override',
        'const', 'static', 'int', 'bool', 'void', 'char', 'double', 'float',
        'return', 'if', 'else', 'for', 'while', 'new', 'delete', 'NULL',
        'true', 'false', 'this', 'using', 'namespace', 'struct', 'enum',
        'auto', 'nullptr'
    }
    types = {
        'User', 'ElderlyUser', 'ProfessionalUser', 'Reminder', 'ReminderManager',
        'FamilyContact', 'DailyCheckIn', 'DailyBriefing', 'VoiceAssistant', 'CareBox',
        'string', 'size_t'
    }
    io_tokens = {'std', 'cout', 'cin', 'endl', 'getline', 'iostream'}

    lines = code_text.splitlines()
    highlighted_lines = []

    for i, line in enumerate(lines, 1):
        # Handle comments first
        comment_match = re.search(r'(//.*)$', line)
        comment_part = ""
        code_part = line
        if comment_match:
            comment_part = f'<span class="tok-comment">{html.escape(comment_match.group(1))}</span>'
            code_part = line[:comment_match.start()]

        # Preprocessor directive
        if code_part.strip().startswith('#'):
            prep_html = f'<span class="tok-prep">{html.escape(code_part)}</span>'
            line_html = prep_html + comment_part
        else:
            # Tokenize strings
            def replace_string(m):
                return f'___STR_{m.group(0)}___'
            
            # String literals
            strings = []
            def str_repl(m):
                idx = len(strings)
                strings.append(m.group(0))
                return f'@@@STR{idx}@@@'
            
            cleaned_code = re.sub(r'("[^"\\]*(?:\\.[^"\\]*)*")', str_repl, code_part)

            # Tokenize words
            def word_repl(m):
                w = m.group(0)
                if w in keywords:
                    return f'<span class="tok-keyword">{w}</span>'
                elif w in types:
                    return f'<span class="tok-type">{w}</span>'
                elif w in io_tokens:
                    return f'<span class="tok-io">{w}</span>'
                elif re.match(r'^\d+$', w):
                    return f'<span class="tok-num">{w}</span>'
                return html.escape(w)

            # Highlight words and punctuation
            parts = re.split(r'(\b[a-zA-Z_]\w*\b|\b\d+\b)', cleaned_code)
            res_parts = []
            for p in parts:
                if re.match(r'^[a-zA-Z_]\w*$', p) or re.match(r'^\d+$', p):
                    res_parts.append(word_repl(re.match(r'^(.*)$', p)))
                else:
                    res_parts.append(html.escape(p))
            
            line_html = "".join(res_parts)

            # Put back strings
            for idx, s in enumerate(strings):
                line_html = line_html.replace(f'@@@STR{idx}@@@', f'<span class="tok-str">{html.escape(s)}</span>')

            line_html = line_html + comment_part

        highlighted_lines.append(f'<div class="code-line"><span class="ln">{i:3d}</span><span class="code-text">{line_html if line_html.strip() else "&nbsp;"}</span></div>')

    return "\n".join(highlighted_lines)

print("Tokenizer ready!")
