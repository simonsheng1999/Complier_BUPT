program ifthen;
　　var year:integer;
　　begin
　　　write("Input year:");read(year);
　　　write(year);
     write(6);
　　　if ((year mod 400)=0 )　then
　　　　write("is a leap year.")
　　　else
　　　　if ((year mod 4)=0)and(year mod 100<>0)
　　　　then write("is a leap year.")
　　　　else write("is not a leap year.");
　　end.