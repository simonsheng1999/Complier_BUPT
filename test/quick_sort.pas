program quicksort;
    var i,n,temp:integer; a:array[1..100] of integer;
    procedure initialize(n:integer);
        var i:integer;
        begin
            for i := 1 to n do
            read(a[i])
        end;
    procedure swap(i,j:integer);
        begin
            temp := a[j];
            a[j] := a[i];
            a[i] := temp
        end;
    procedure quicksort(l,r:integer);
        var p, m, tmp, ind:integer;
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
    begin
       read(n);
       if n <= 100 then
       begin
            initialize(n);
            quicksort(1, n);
            for i := 1 to n do
            begin
                write(a[i]);
                write(" ");
            end
       end
    end.