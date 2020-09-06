program array_list;
   type arr=array[1..10]of integer; //{说明一数组类型arr}
   var a:arr;i:integer;
   begin
    write("Enter 10 integer:");
    for i:=1 to 10 do read(a[i]) ;//{从键盘上输入10个整数}
    for i:=10 downto 1 do //{逆序输出这10个数}
      write(a[i]);
       write(" ");
   end.