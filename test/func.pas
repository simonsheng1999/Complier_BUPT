program func;
　　　var i:integer;
　　　procedure draw_a_line(n:integer); //{该过程打印出连续n 个星号,并换行}
　　　　var j:integer;
　　　　begin
　　　　　for j:=1 to n do
　　　　　　write("*\n");
　　　　end;
　　begin
　　　for i:=1 to 6 do
　　　　draw_a_line(i);{调用过程,第I行打印i个连续星号}
　　end.