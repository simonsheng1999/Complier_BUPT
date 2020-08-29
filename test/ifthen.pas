program ifthen;
　　var year:integer;
　　begin
　　　write('Input year:');readln(year);
　　　write(year:6);
　　　if (year mod 400=0 )　then
　　　　writeln('is a leap year.')
　　　else
　　　　if (year mod 4=0)and(year mod 100<>0)
　　　　then writeln('is a leap year.')
　　　　else writeln('is not a leap year.');
　　end.