topic_model = BERTopic(embedding_model="distiluse-base-multilingual-cased-v1", calculate_probabilities=True, verbose=True)
topics, probs = topic_model.fit_transform(dataset.OriginalTweet.to_list())
