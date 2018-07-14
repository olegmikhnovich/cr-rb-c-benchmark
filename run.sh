# Compile C code
gcc -O3 -o towerc tower.c

# Compile Crystal code
crystal build tower.cr --release

# Run benchmarks

# C code
./towerc

# Crystal code
./tower

# Ruby code
ruby tower.rb

# Cleanup
rm towerc
rm tower
