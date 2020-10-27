#Importing data
!wget --no-check-certificate \
  https://storage.googleapis.com/laurencemoroney-blog.appspot.com/bbc-text.csv \
  -O /tmp/bbc-text.csv

import pandas as pd
data=pd.read_csv(r"bbc-text.csv")
  
#Visualize the topic based clustering for words in doc_term_matrix
from gensim.models import ldamodel
# Instantiate LDA model
lda = ldamodel.LdaModel

#Fit LDA model on the dataset
num_topics=14
%time ldamodel = lda(doc_term_matrix,num_topics=num_topics,id2word=dictionary,passes=50,minimum_probability=0)

# Print the topics identified by LDA model
ldamodel.print_topics(num_topics=num_topics)

#Visualize the model
from pyLDAvis import gensim
lda_display = pyLDAvis.gensim.prepare(ldamodel, doc_term_matrix, dictionary, sort_topics=False, mds='mmds')
pyLDAvis.display(lda_display)
