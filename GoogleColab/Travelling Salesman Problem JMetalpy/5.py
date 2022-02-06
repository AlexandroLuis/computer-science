# define algorithm to use
maxevals = 99999999

popsize = 400
offspring = 400
mut_prob = 0.05
cross_prob = 0.9

select = BinaryTournamentSelection(
                        MultiComparator([StrengthRanking.get_comparator(),
                                         KNearestNeighborDensityEstimator.get_comparator()]
                                       ))

termin = termination_criterion.StoppingByEvaluations(max_evaluations=maxevals)

algorithm = GeneticAlgorithm(
    problem=myproblem,
    population_size=popsize,
    offspring_population_size=offspring,
    mutation=PermutationSwapMutation(mut_prob),
    crossover=PMXCrossover(cross_prob),
    selection=select,
    termination_criterion=termin
)

params = {'population':popsize, 
          'offspring':offspring, 
          'mutation probability': mut_prob, 
          'crossover probability': cross_prob,
         }
