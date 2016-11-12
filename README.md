## ��������� ���������� �������
	/ - ������ (����� ooad-course-lab)
	./src - �������� ����
	    ./commands_system - ������ ���� ������
	                    ./db - ��� ���������� ���� ������ (����� ������ ����� *.h)
	                    ./db/imp - ��� � ���������� (*.cpp), ����� ����������
	                    ./http_view
	                    ./http_view/imp
	                    ./model
	                    ./model/imp
	                    ./presentor
	                    ./presentor/imp
	                    ./utils - ������ ������� (*.h ������������, assert*, Exception, ...)
	                    ./utils/imp - ���������� ����� ���� (��� �������� ���� ��. ����)
	
	./devtools - ��� ��������� ������ ������ visual studio
	         ./msvs2010 - �� ������ ������ ������ 2010 (��� �������� ����, ��. ����)
	                  ./commands_system - �������� ��� project

> ����������. ������ ��� ���� ������ � ����� utils. ��������� ����� ���� ������ � ������, �� ����� ����� ��������� �����.

## �������� ����� ��� ������ (master �� �������)
* ����� - volkov
* ������� - ryabinkin
* ������� - grosheva
* ������� - solovev

## �������������� ��������� (������������)
0.	cd <���� ���������� ��� ����� �������>
	* �� �����������, ����� ������ ����� �����������
0.	git clone https://github.com/qwert182/ooad-course-lab
	* ������� ��� ����� "ooad-course-lab" � ��������
0.	cd ooad-course-lab
0.	explorer .
	* �������� � � ���������� (��� windows), � ���������, ����������, ��������� ����� (���� �� ���)
0.	git config user.name
0.	git config user.email
	* ���� ������ �� ������, �� �� ����� ������:
		- git config user.name "������� ���"
		- git config user.email "��� email � github.com"
0. git checkout <���� �����>
	* ����������� �� �����. ���� ������ �� ������, �� � ���� ������� � �������������:
		- git branch <���� �����>
		- git checkout <���� �����>

## ���������� visual studio
0.	������� ������� ������
0.	���� / ������� / ������...
0.	� �������� (���, ��� CLR, Win32) �������
	* ������ ���� �������� / ������� Visual Studio / ����� �������
0.	������
	* ���: OOAD
	* ������������: ...\ooad-course-lab\devtools\
0.	������ OK
0.	������� ������
0.	������� ���� (...\ooad-course-lab\devtools\)
0.	������������� ����� OOAD --> msvs<���_������>
0.	������� ��� (...\ooad-course-lab\devtools\msvs<���_������>) OOAD.sln (������� � ����� ������)
0.	���� / �������� / ������� ������...
0.	���� / �������� / ������� ������...
0.	� �������� �������
	* Visual C++
	* Win32
	* ���������� ���������� Win32
0.	������
	* ���: commands_system
	* ������������ �� �������
0.	������ OK
0.	������ ����� >
0.	������� ��� ������� ���������
0.	����� ��������� ����� "������ ������"
0.	������ ������
0.	� ������������ ������� � ������� "commands_system" ������� ����� (��� ���������� �������)
	* ������������ �����
	* ����� ��������� ����
	* ����� ��������
0.	������� ����� (�������) ��� � "��������� ���������� �������" ������� � ����� "src"
0.	�������� � ������ ����� (������) ����� (��������� *.h, *.cpp, *.c) �� ��������������� ����� �������
0.	�������� ��������� �. �. � ���������� ������ (���� ��� �������� .gitignore)
0.	������ ��. ������ � git


## ������ � �������� � visual studio (� ��� ����� ��� 2010)
*	��������� �������� � ������ � ������������ ������� ������ ��������������� �������� ��������� �� �����


## ������ � git
�� ���-�� ��������/��������/������� � ���� ������ ��� ���������, ������

0.	cd .../ooad-course-lab
	* ������� � ������ �������
0.	git branch
	* ���������, ��� �����, ���������� '*', ���� ����� ������ (git checkout)
0.	git status
	* ������� ���������� ����� � �����, ���� �� ��������� (��������� ���������, ��� �������� ������ (*.exe)), �����
	* ����������. ����� �������� � ���������� ������ ����� ��������� (� ������� ������, ������� ����� git status � ���������� ���� "use ... to unstage").
0.	git add <����/�����> ��� git add .
	* ������� ����� ��� commit
	* ����������. "git add ." ������� � ������� �� �������.
0.	git status
	* ������� ���������� ����� � �����, ���� �� ��������� (��������� ����, ��� �������� ������ (*.exe, *.pdb, � �. �.)), �����
0.	git commit -m "��� ������ (�� ���������� �� �����������)"
	* ���� ���������� ��� (�. �. �����������) � ��������� �� ������� ����
0.	git push origin HEAD
	* �������� �� ������ (� �������� clone ������)

