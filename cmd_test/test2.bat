@echo off

echo er >test.txt
rem д�����
echo.>>test.txt
echo abc�� >>test.txt
echo 425 >>test.txt
echo 425evrabc >>test.txt
echo evr425abcde >>test.txt
::C:\Windows\System32\find /N "111" test.txt
::type test.txt|C:\Windows\System32\find /N "111"
::del test.txt
rem �ҵ������ַ������������ַ������
::findstr . test.txt
rem �ҵ������ַ����������ַ������
::findstr .* test.txt

::findstr "[0-9]" test.txt
::findstr "[a-z][A-Z]" test.txt
::findstr "[abcefg]" test.txt
::findstr "[a-df-z]" test.txt

::���������ֿ�ͷ
::findstr "^[0-9]" test.txt

::findstr "^[0-9]*$" test.txt
rem ������9���ַ��������뵽2.txt��
::findstr ......... test.txt>2.txt

::findstr �� test.txt

set a=4
set a=5 & echo %a%
echo %a%
rem ���������ӳ٣�Ҫ��!a!���
setlocal enabledelayedexpansion
set a=6 & echo !a!

::�������<,>,&��ǰ�����ţ�ʹʧȥ����
echo test ^>test.txt

::���з���
echo Ӣ^
��

for /r d:\ %%i in (*�˺�*) do (
set var=%%i

for /r "delims==" %%a in (!var!) do (
echo %%~nxa
set var3=%%~nxa
set var4=!var3:��=�˺�!
echo !var4!
ren %%i !var4!)
)

echo %errorlevel%
echo ������ʾ�� & pause > nulf: