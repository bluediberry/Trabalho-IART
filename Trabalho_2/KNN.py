import pandas as pd 
import numpy as np 
import math
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
from sklearn.neighbors import KNeighborsClassifier
from sklearn.metrics import confusion_matrix
from sklearn.metrics import f1_score
from sklearn.metrics import accuracy_score

dataset = pd.read_csv('test_file.txt', header = None)

X = dataset.iloc[:, 0:9]
y = dataset.iloc[:, 9]
X_train, X_test, y_train, y_test= train_test_split(X,y, random_state=0, test_size=0.25)

sc_X = StandardScaler()
X_train = sc_X.fit_transform(X_train)
X_test = sc_X.transform(X_test)

#n_neighbors=sqrt(n), n=60, sqrt(60)=7.7, 7 is odd
classifier = KNeighborsClassifier(n_neighbors=7, p=2, metric='euclidean')

classifier.fit(X_train, y_train)

KNeighborsClassifier(algorithm='auto', leaf_size=30, metric='euclidean', 
                    metric_params=None, n_jobs=1, n_neighbors=7, p=2,
                    weights='uniform')

cm = confusion_matrix(y_test, y_pred)
f1_score(y_test, y_pred)
accuracy_score(y_test,y_pred)