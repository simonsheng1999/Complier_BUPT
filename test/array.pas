program array;
　　type arr=array[1..10]of integer; {说明一数组类型arr}
　　var a:arr;i:integer;
　　begin
　　　writeln('Enter 10 integer:');
　　　for i:=1 to 10 do read(a[i])；{从键盘上输入50个整数}
　　　readln;
　　　for i:=10 downto 1 do {逆序输出这50个数}
　　　　write(a[i]:10);
　　end.