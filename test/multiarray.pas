program multiarray;
  const n=3;
  var a:array[1..3,1..3]of integer;i,j:integer;
  begin
   for i:=1 to 3 do
   begin
    for j:=1 to 3 do
     read(a[i,j]);
   end;
  for i:=1 to 3 do
  begin
   for j:=1 to 3 do
        begin
            write(a[j,i]);
            write(" ");
            end
  end;
    write("\n");
  end.