dataset = dataset.dropna().sample(20000)
dataset.reset_index(inplace=True,drop=True)
dataset
