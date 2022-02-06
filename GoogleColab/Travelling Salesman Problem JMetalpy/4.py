# instantiate problem to solve
problem_name = 'Djibouti 38 TSP'
optimal_fitness = 6656
dist_matrix, nb_cities, cities_coord = read_tsplib_file('/dj38.tsp') # your cities archieve 
myproblem = myTSP(dist_matrix, nb_cities)
