
watch( "(include|src|test).*\.[ch]pp$" ) do |match|
  puts match.to_s
  system 'tup upd && cd build && ./test_all_stuff && cd ..'
end

