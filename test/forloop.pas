program forloop;
   var
　　　　n,i : integer；｛i为循环变量｝
　　　　S : longint;｛s作为累乘器｝
　　begin
　　　write('Enter n=');readln(n);{输入n}
　　s:=1;
　　　for i:=2 to n do｛从2到n累乘到s中｝
　　　　s:=s*i;
　　　writeln(n,'!=',s);｛输出n!的值｝
　　end.