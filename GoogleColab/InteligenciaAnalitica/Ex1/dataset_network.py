def compute_network(matrix,seed=0,min_dcos=0.7,max_neighbors=3,max_nodes=1000):
  
  G=nx.Graph()
  visited = []
  visited.append(seed)
  total = matrix.shape[0]
  temp = {}
  
  while(True):
  
    seed = visited.pop()
    temp[seed]=1
  
    neighbors = {}

    for i in range(0,total):
      if seed==i: continue
      if i in temp: continue
      dcos = dis_cosine(matrix,i,seed)
      if dcos <= min_dcos:
        neighbors[i] = dcos

    sorted_x = sorted(neighbors.items(), key=lambda kv: kv[1])

    counter=0
    for item in sorted_x:
      G.add_edge(seed, item[0], weight=(1-item[1]))
      if item[0] not in temp: visited.append(item[0])
      counter+=1
      if (counter >= max_neighbors): break     

  
    if(len(G) >= max_nodes): break
    if(len(visited)==0): break
    
    
    
  return G
    
G = compute_network(vsm,min_dcos=0.8,seed=1)
nx.info(G)
