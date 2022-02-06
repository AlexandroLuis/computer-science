#run algorithm and print solution
fitness_log = []

progress_bar = ProgressBarObserver(max=maxevals)
algorithm.observable.register(progress_bar)

algorithm.run()
result = algorithm.get_result()
print_solution(algorithm, result, fitness_log, params)
