# Python Script Specification for Converting *.JOB Files to CSV

## 규칙

1. **파일 포맷**: 이 파일은 기본적으로 CSV와 유사한 포맷을 가지고 있습니다.
2. **파일 확장자**: 파일의 확장자는 `*.JOB`입니다.
3. **구분자**: 파일 내용은 CSV처럼 `,`로 구분되지 않고, 별도의 문자로 구분됩니다.
4. **예시 구분자**: 예를 들어, 어떤 파일은 `+_+`로 구분되어 있습니다.
5. **구분자 교체**: 구분자를 쉽게 수정할 수 있도록 전역 변수를 사용하여 구분자를 설정합니다.
6. **다중 구분자**: 구분자는 2개 이상일 수 있으며, 구분자는 배열로 포함되어 프로그램이 실행될 때 이 배열을 참조합니다.
7. **목적**: 이 프로그램의 최종 목적은 특이한 형태의 `*.JOB` 파일을 일반적인 CSV 파일로 변환하는 것입니다.
8. **파일 생성**: 원본 파일은 그대로 두고, 새로운 CSV 파일을 생성합니다.

1. **File Format**: This file basically has a format similar to CSV.
2. **File Extension**: The file extension is `*.JOB`.
3. **Delimiter**: The file contents are not separated by `,` like CSV, but by separate characters.
4. **Example Delimiter**: For example, some files are separated by `+_+`.
5. **Replace Delimiter**: Set the delimiter using a global variable so that you can easily modify the delimiter.
6. **Multiple Delimiters**: There can be more than 2 delimiters, and the delimiters are included in an array, and this array is referenced when the program is executed.
7. **Purpose**: The ultimate goal of this program is to convert a special-shaped `*.JOB` file into a general CSV file.
8. **Create File**: Leave the original file as is, and create a new CSV file.

## 설명

### 한국어
이 프로그램은 지정된 디렉토리와 그 하위 디렉토리에서 `.job` 파일을 검색하고, 각 파일을 CSV 형식으로 변환합니다. `jobfile_search_and_run.py` 스크립트는 `.job` 파일을 찾고, `jobfile_manage.py` 스크립트를 실행하여 변환을 수행합니다. 변환 과정에서, 파일의 첫 번째 줄을 읽어 구분자를 감지하고, 해당 구분자를 사용하여 CSV 파일을 생성합니다. 만약 구분자가 감지되지 않으면 오류가 발생합니다. 변환된 CSV 파일은 원본 파일과 동일한 디렉토리에 저장됩니다.

### English
This program searches for `.job` files in a specified directory and its subdirectories, and converts each file into a CSV format. The `jobfile_search_and_run.py` script locates `.job` files and executes the `jobfile_manage.py` script to perform the conversion. During the conversion process, the first line of the file is read to detect the delimiter, and the detected delimiter is used to generate the CSV file. If no delimiter is detected, an error is raised. The converted CSV file is saved in the same directory as the original file.

## 추가적인 고려사항 및 추천 기능

- **구분자 자동 감지**: 파일을 읽을 때 구분자를 자동으로 감지하는 기능을 추가하면 사용자가 구분자를 수동으로 입력할 필요가 없어 편리할 수 있습니다.
- **에러 처리**: 파일을 읽거나 쓸 때 발생할 수 있는 에러를 처리하는 로직을 추가하여 프로그램의 안정성을 높일 수 있습니다.
- **로그 기능**: 변환 과정에서의 로그를 기록하여 사용자가 변환 과정을 추적할 수 있도록 하면 좋습니다.
- **사용자 인터페이스**: GUI 또는 CLI 옵션을 제공하여 사용자가 더 쉽게 프로그램을 사용할 수 있도록 할 수 있습니다.
- **테스트 케이스**: 다양한 구분자와 파일 구조에 대한 테스트 케이스를 작성하여 프로그램의 신뢰성을 높일 수 있습니다.


