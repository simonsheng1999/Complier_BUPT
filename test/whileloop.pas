program whileloop;
　　var m,n,a,b,r:integer;
　　begin
　　　　write("Input m,n:");
　　　　read(m,n);
　　　　a:=m;b:=n;r:=a mod b;
　　　　while r<>0 do
　　　　begin
　　　　　a:=b;b:=r;
　　　　　r:=a mod b;
　　　　end;
　　　　write("The greatest common divide is : ");
       write(b);
　　end.