def compute_bag_of_words(dataset,lang,domain_stopwords=[]):
  
  d = []
  for index,row in dataset.iterrows():
    text = row['title'] #texto do evento
    text2 = remove_stopwords(text, lang,domain_stopwords)
    text3 = stemming(text2, lang)
    d.append(text3)
  
  matrix = CountVectorizer(max_features=1000)
  X = matrix.fit_transform(d)
  
  count_vect_df = pd.DataFrame(X.todense(), columns=matrix.get_feature_names())

  return count_vect_df


bow = compute_bag_of_words(dataset,'portuguese')
bow
