define do_trace
  set logging redirect on
  set logging file ./trace
  set logging overwrite on
  set logging debugredirect on
  set logging enabled on
  set $count=0
  while ($pc != $arg0 && $pc > 0x20000000)
    stepi
    set $count=$count+1
  end
  set logging enabled off
  print $count
end

