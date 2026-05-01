# Vigenère Cipher Implementation (C)

이 프로젝트는 다중 치환 암호의 일종인 **비즈네르 암호(Vigenère Cipher)**를 C 언어로 구현한 보안 프로그래밍 예제입니다.

## 1. 프로젝트 개요
*   **비즈네르 암호**: 키워드를 사용하여 평문을 암호화하는 방식으로, 단일 치환 암호의 단점인 빈도 분석 공격을 보완한 알고리즘입니다.
*   **메모리 기반 연산**: 본 프로그램은 26x26 비즈네르 표를 메모리에 생성하여 암호화 로직을 수행합니다.

## 2. 주요 기능 및 특징
*   **비즈네르 표 자동 생성**: 프로그램 실행 시 2차원 배열(`char vigenere[26][26]`)을 활용하여 암호화용 알파벳 표를 동적으로 생성합니다.
*   **안정적인 입력 처리**: `fgets`를 사용하여 버퍼 오버플로우를 방지하고, 유효하지 않은 입력(공백, 특수문자 등)에 대한 예외 처리가 포함되어 있습니다.
*   **키워드 정제**: 사용자가 입력한 키에서 공백과 개행을 자동으로 제거하며, 대문자는 소문자로 통일하여 처리합니다.
*   **키 반복 로직**: 평문보다 키워드가 짧을 경우, 키워드를 순환(Modulo 연산)하여 암호화를 지속합니다.
*   **특수문자 보존**: 평문 내의 공백이나 특수문자는 암호화하지 않고 그대로 유지하여 가독성을 높였습니다.

## 3. 암호화 원리
본 프로그램은 다음과 같은 논리 구조를 따릅니다.
1.  **Key 처리**: 키워드의 공백을 제거하고 순수 알파벳으로만 구성합니다.
2.  **Mapping**: 평문 알파벳 $P$와 키워드 알파벳 $K$를 비즈네르 표의 인덱스로 매핑합니다.
3.  **Result**: `vigenere[K-97][P-97]` 위치의 문자를 출력합니다.

## 4. 실행 방법
GCC 컴파일러를 사용하여 다음과 같이 실행할 수 있습니다.

### 컴파일
```bash
gcc -o vigenere Vigenere_Cipher.c
```
실행
```bash
./vigenere
```
5. 정상적인 실행 예시
Plaintext
KEY를 입력하시오 (알파벳과 공백만 가능합니다) :
secret is beautiful
암호화할 평문을 입력하시오 :
wish to be free from myself

=> OMUY XH JW GVEY YZTG XQWGCJ


[English Version] (.translated by Gemini AI)

This project is a security programming example that implements the Vigenère Cipher, a type of polyalphabetic substitution cipher, using the C language.
   
1. [Project Overview]
   -The Vigenère cipher encrypts plaintext by using a keyword, providing better resistance against frequency analysis compared to simple substitution ciphers.
   -This program generates a $26 \times 26$ Vigenère table in memory to perform the encryption logic.
      
2. [Key Features]
   -Automatic Table Generation: Dynamically creates an alphabet table for encryption using a 2D array (char vigenere[26][26]) upon execution.
   -Secure Input Handling: Uses fgets to prevent buffer overflow and includes exception handling for invalid inputs (empty strings, etc.).
   -Keyword Refinement: Automatically removes spaces and newlines from the user-provided key and standardizes all characters to lowercase.
   -Key Rotation Logic: If the keyword is shorter than the plaintext, it cycles through the keyword (using Modulo operation) to continue encryption.
   -Preservation of Special Characters: Spaces and special characters in the plaintext are kept as-is without encryption to maintain readability.
      
3. [Encryption Principle]
   -The program follows these logical steps:Key Processing: Cleans the keyword to consist only of pure alphabetic characters.
   -Mapping: Maps the plaintext alphabet $P$ and keyword alphabet $K$ to the indices of the Vigenère table.
   -Result: Outputs the character at the vigenere[K-97][P-97] position.

4. [How to Run]
   You can run the program using the GCC compiler as follows:
   # Compile
   gcc -o vigenere Vigenere_Cipher.c

   # Run
   ./vigenere

5. [Execution Example] (code does not support English)
   KEY를 입력하시오 (알파벳과 공백만 가능합니다) :
   secret is beautiful
   암호화할 평문을 입력하시오 :
   wish to be free from myself

   => OMUY XH JW GVEY YZTG XQWGCJ
