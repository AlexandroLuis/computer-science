def dis_cosine(matrix, e1, e2):
  dcos = cosine(matrix.iloc[e1,:], matrix.iloc[e2,:])
  return dcos


# exemplo: dissimilaride entre o primeiro (id=0) e o segundo evento (id=1) do vsm-tfidf
dis_cosine(vsm,0,1)
