file(REMOVE_RECURSE
  "myTest"
  "myTest.pdb"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/myTest.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
