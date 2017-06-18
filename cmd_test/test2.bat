@echo off

echo er >test.txt
rem 写入空行
echo.>>test.txt
echo abc我 >>test.txt
echo 425 >>test.txt
echo 425evrabc >>test.txt
echo evr425abcde >>test.txt
::C:\Windows\System32\find /N "111" test.txt
::type test.txt|C:\Windows\System32\find /N "111"
::del test.txt
rem 找到任意字符，不包括空字符或空行
::findstr . test.txt
rem 找到任意字符，包括空字符或空行
::findstr .* test.txt

::findstr "[0-9]" test.txt
::findstr "[a-z][A-Z]" test.txt
::findstr "[abcefg]" test.txt
::findstr "[a-df-z]" test.txt

::查找以数字开头
::findstr "^[0-9]" test.txt

::findstr "^[0-9]*$" test.txt
rem 将超过9个字符的行输入到2.txt中
::findstr ......... test.txt>2.txt

::findstr 我 test.txt

set a=4
set a=5 & echo %a%
echo %a%
rem 启动变量延迟，要用!a!输出
setlocal enabledelayedexpansion
set a=6 & echo !a!

::特殊符号<,>,&的前导符号，使失去意义
echo test ^>test.txt

::续行符号
echo 英^
雄

for /r d:\ %%i in (*账号*) do (
set var=%%i

for /r "delims==" %%a in (!var!) do (
echo %%~nxa
set var3=%%~nxa
set var4=!var3:我=账号!
echo !var4!
ren %%i !var4!)
)

echo %errorlevel%
echo 其他提示语 & pause > nulf: