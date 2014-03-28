003LinkedListChain
==================

Linked List응용. LL연결, 역순 출력, 삽입, 삭제 등등


COMP216-002 자료구조응용 
LAB #9
2013. 4. 10.


1) 두 개의 chain을 연결하여 하나의 chain으로 만들어 출력하는 프로그램을 작성하시오. (동적 메모리 할당을 사용)

%cat input.txt
3  8  23   5   17   23		// chain 1
78  12  5   7   34  29		// chain 2

%cat output.txt
3  8  23   5   17   23	 78  12  5   7   34  29	

2) 입력 데이터를 읽어 순서대로 chain을 구성하시오. (동적 메모리 할당을 사용)

① chain을 역순으로 변경하여 입력 데이타를 역순으로 출력하는 프로그램을 작성하시오.

%cat input.txt
 3    8   23    5    17    23

%cat output.txt
23   17    5   23     8     3

②  linked 스택을 사용하여 역순으로 출력하는 프로그램을 작성하고 ①의 과정과 비교해 보시오.


③ chain에 하나의 노드를 삽입한 결과를 출력하시오.

%cat input.txt
 3    8   23    5    17    23    19       // chain 
 4   100				       // chain의 4번째 노드 다음 100을 삽입

%cat output.txt
 3    8   23    5   100    17    23    19

④ chain에서 하나의 노드를 삭제한 결과를 출력하시오.

%cat input.txt
 3    8   23    5    17    23	  19 	// chain 
 4   				        // chain의 4번째 노드를 삭제

%cat output.txt
 3    8   23   17    23	   19

⑤ chain의 길이를 출력하시오.

%cat input.txt
 3    8   23    5    17    23

%cat output.txt
 6


3) 입력 데이터를 읽어 순서대로 doubly linked circular list with header node를 구성하시오. (동적 메모리 할당을 사용)

① 입력 데이타를 역순으로 출력하는 프로그램을 작성하시오.

%cat input.txt
 3    8   23    5    17    23

%cat output.txt
23   17    5   23     8     3


② 리스트에 하나의 노드를 삽입한 결과를 출력하시오.

%cat input.txt
 3    8   23    5    17    23    19       // 리스트 
 4   100				       // 리스트의 4번째 노드 다음 100을 삽입

%cat output.txt
 3    8   23    5   100    17    23    19

③ 리스트에서에서 하나의 노드를 삭제한 결과를 출력하시오.

%cat input.txt
 3    8   23    5    17    23	  19 	// 리스트 
 4   				        // 리스트의 4번째 노드를 삭제

%cat output.txt
 3    8   23   17    23	   19

④ 리스트의 길이를 출력하시오.

%cat input.txt
 3    8   23    5    17    23

%cat output.txt
 6

