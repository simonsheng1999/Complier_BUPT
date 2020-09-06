program multiarray;
  const n=3;
  var a:array[1..n,1..n]of integer;i,j:integer;
  begin
   for i:=1 to n do
   begin
    for j:=1 to n do
     read(a[i,j]);
   end;
  for i:=1 to n do
  begin
   for j:=1 to n do
    write(a[j,i]);
       write(" ");
  end;
    write("\n");
  end.