require "benchmark"

N = 20
A = Array(Int32).new 
B = Array(Int32).new 
C = Array(Int32).new 

LOG = false

def move(n, source, target, auxiliary)
    if n > 0
        move(n - 1, source, auxiliary, target)
        target << source.pop
        print "********\n#{A}\n#{B}\n#{C}\n" if LOG
        move(n - 1, auxiliary, target, source)
    end
end

def run()
    (1..N).each { |v| A << v }
    A.reverse
    move(N, A, C, B)
end

puts "\nCrystal work time: #{Benchmark.measure { run() } }" 