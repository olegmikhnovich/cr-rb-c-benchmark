require 'benchmark'

N = 20
A = Array.new
B = Array.new
C = Array.new

LOG = false

def move(n, source, target, auxiliary)
    if n > 0
        move(n - 1, source, auxiliary, target)
        target.append(source.pop)
        print "********\n#{A}\n#{B}\n#{C}\n" if LOG
        move(n - 1, auxiliary, target, source)
    end
end

def run()
    (1..N).each { |v| A << v }
    A.reverse
    move(N, A, C, B)
end

puts "\nRuby work time: #{Benchmark.measure { run() } }" 