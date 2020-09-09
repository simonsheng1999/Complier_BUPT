program quick_sort;
var i, n, a[1..100];
procedure initialize(n);forward;
procedure swap(i, j);
var temp;
begin
   temp := a[j];
   a[j] := a[i];
   a[i] := temp
end;
procedure quicksort(l, r);
var p, m, tmp, ind;
var m;
begin
    if l < r then
        begin
            p := a[l];
            m := l;
            for ind := (l + 1) to r do
                if a[ind] < p then
                    begin
                        m := (m + 1);
                        tmp := a[m];
                        a[m] := a[ind];
                        a[ind] := tmp
                    end;
            
            a[l] := a[m];
            a[m] := p;
            quicksort(l, m - 1);
            quicksort(m + 1, r)
        end
end;
procedure initialize;
var i;
begin
   for i := 1 to n do
      read(a[i])
end;
begin
   read(n);
   if n <= 100 then
   begin
        initialize(n);
        quicksort(1, n);
        for i := 1 to n do
            begin
                write(a[i])
                write(" ")
            end
   end
end.
