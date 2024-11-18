import os
import pandas as pd

def csv_to_html():
    # 현재 디렉토리의 모든 파일을 검색
    for filename in os.listdir('.'):
        # 파일이 CSV 파일인지 확인
        if filename.endswith('.csv'):
            # CSV 파일을 읽기
            df = pd.read_csv(filename)
            
            # 스타일링 함수 정의
            def highlight_skip(s):
                return ['color: lightgray' if 'skip' in str(v) else '' for v in s]

            # HTML로 변환 (스타일 적용)
            html_content = df.style.apply(highlight_skip, axis=1).to_html(index=False)
            
            # HTML 파일 이름 설정
            html_filename = filename.replace('.csv', '.html')
            # HTML 파일로 저장
            with open(html_filename, 'w', encoding='utf-8') as f:
                f.write(html_content)
            print(f"Converted {filename} to {html_filename}")

if __name__ == "__main__":
    csv_to_html()
