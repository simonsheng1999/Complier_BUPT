program case;
　　var x,y:real;
　　begin
　　　write('Input x:');readln(x);
　　　case trunc(x/100) of
　　　　0:y:=x+1;
　　　　1:y:=x-1;
　　　　else y:=0;
　　　end;{end of case}
　　　writeln('x=',x:8:2),'y=',y:8:2);
　　end.