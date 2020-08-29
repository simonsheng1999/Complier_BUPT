program pointer_;
Type pointer=^integer;
　　var p1,p2:pointer;
　　procedure swap(var q1,q2:pointer);
　　　var q:pointer;
　　　begin
　　　　q:=q1;
　　　　q1:=q2;
　　　　q2:=q;
　　　end;
　　begin
　　　new(p1);new(p2);
　　　write('Input 2 data:');readln(pq^,p2^);
　　　if p1^>p2^ then swap(p1,p2);
　　　writeln('Output 2 data:',p1^:4,p2^:4);
　　end.
