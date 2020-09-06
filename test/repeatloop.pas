program repeatloop.pas;
   var
    m,n,a,b,r : integer;
  begin
   write("Input m,n=");
   read(m,n);
   a:=m;b:=n;
   repeat
    r:=a mod b;
    a:=b;b:=r;
   until r=0;
   write("The greatest common divide is : ");
     write(a);
  end.