import numpy as np
import matplotlib.pyplot as plt
from ypstruct import structure

# Sphere Function
def sphere(x):
    return sum(x ** 2)

# Antigen
antigen = structure()
antigen.affinity_function = sphere
antigen.nvar = 5
antigen.varmin = [-10, -10, -1, -5, 4]
antigen.varmax = [10, 10, 1, 5, 10]

# Clonalg
clonalg = structure()
clonalg.popsize = 10
clonalg.nToBeCloned = clonalg.popsize // 2
clonalg.nClones = 2
clonalg.mutationRate = 0.5
clonalg.mutationIntensity = 0.1

# Initialize Antibody Population - Steps 1 and 2
empty_antibody = structure()
empty_antibody.receptors = None
empty_antibody.affinity = None

pop = empty_antibody.repeat(clonalg.popsize)
for i in range(clonalg.popsize):
    pop[i].receptors = np.random.uniform(antigen.varmin, antigen.varmax, antigen.nvar)
    pop[i].affinity = antigen.affinity_function(pop[i].receptors)

# Select the antibodies to be cloned - Step 3
pop = sorted(pop, key=lambda x: x.affinity)
popToBeCloned = pop[0:clonalg.nToBeCloned]

# Generate clone population - Step 4
clonePop = []

for i in range(clonalg.nToBeCloned):
    clonePop += popToBeCloned[i].repeat(clonalg.nClones)

# Hypermutation - Step 5
def hypermutation(x, mutationRate, mutationIntensity):
    y = x.deepcopy()
    flag = np.random.rand(*x.receptors.shape) <= mutationRate
    indices = np.argwhere(flag)
    maximum = np.array(antigen.varmax)[indices]
    minimum = np.array(antigen.varmin)[indices]
    scale = maximum - minimum
    full_scale = mutationIntensity * scale

    y.receptors[indices] += (-0.5 + np.random.rand(*indices.shape)) * full_scale
    # size = indices.shape
    # for i in range(size[0]):
    #  if np.random.rand(1) <= 0.5:
    #    y.receptors[indices[i]] -= np.random.rand(1) * full_scale[indices[i]]
    #  else:
    #    y.receptors[indices[i]] += np.random.rand(1) * full_scale[indices[i]]
    return y

# pre calculate the full scale once
maximum = np.array(antigen.varmax)
minimum = np.array(antigen.varmin)
scale = maximum - minimum
full_scale = clonalg.mutationIntensity * scale

def hypermutation_optimized(x, mutationRate, full_scale):
    y = x.deepcopy()
    flag = np.random.rand(*x.receptors.shape) <= mutationRate
    indices = np.argwhere(flag)

    y.receptors[indices] += (-0.5 + np.random.rand(*indices.shape)) * full_scale[indices]
    # size = indices.shape
    # for i in range(size[0]):
    #  if np.random.rand(1) <= 0.5:
    #    y.receptors[indices[i]] -= np.random.rand(1) * full_scale[indices[i]]
    #  else:
    #    y.receptors[indices[i]] += np.random.rand(1) * full_scale[indices[i]]
    return y

# Testing...
# for i in range(clonalg.popsize):
#  print(pop[i])

# print()

# for i in range(clonalg.nClones * clonalg.nToBeCloned):
#  print(clonePop[i])

print(clonePop[0])
hypermutated = hypermutation_optimized(clonePop[0], clonalg.mutationRate, full_scale)
print(hypermutated)
