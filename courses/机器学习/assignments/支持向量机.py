import numpy as np
import matplotlib.pyplot as plt
from sklearn.svm import SVC
from sklearn.preprocessing import StandardScaler
from sklearn.decomposition import PCA
from sklearn.model_selection import cross_val_score

X = np.array([
    [0,0,0,0,0,0], [1,0,1,0,0,0], [1,0,0,0,0,0], [0,0,1,0,0,0], [2,0,0,0,0,0],
    [0,1,0,0,1,1], [1,1,0,1,1,1], [1,1,0,0,1,0], [1,1,1,1,1,0], [0,2,2,0,2,1],
    [2,2,2,2,2,0], [2,0,0,2,2,1], [0,1,0,1,0,0], [2,1,1,1,0,0], [1,1,0,0,1,1],
    [2,0,0,2,2,0], [0,0,1,1,1,0]
])
y = np.array([1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0])

test = np.array([[0,0,0,0,0,0]])

scaler = StandardScaler()
X_scaled = scaler.fit_transform(X)
test_scaled = scaler.transform(test)

model = SVC(kernel='rbf')
model.fit(X_scaled, y)

cv_scores = cross_val_score(model, X_scaled, y, cv=5)

result = model.predict(test_scaled)

print("测试样本：", test[0])
print("模型预测结果：", result[0])
print(f"交叉验证准确率（5折）：{cv_scores.mean():.2f} (±{cv_scores.std():.2f})")

pca = PCA(n_components=2)
X_pca = pca.fit_transform(X_scaled)

h = 0.02
x_min, x_max = X_pca[:, 0].min() - 1, X_pca[:, 0].max() + 1
y_min, y_max = X_pca[:, 1].min() - 1, X_pca[:, 1].max() + 1
xx, yy = np.meshgrid(np.arange(x_min, x_max, h), np.arange(y_min, y_max, h))

model_pca = SVC(kernel='rbf')
model_pca.fit(X_pca, y)
Z = model_pca.predict(np.c_[xx.ravel(), yy.ravel()])
Z = Z.reshape(xx.shape)

plt.figure(figsize=(10, 6))
plt.contourf(xx, yy, Z, cmap=plt.cm.coolwarm, alpha=0.8)
plt.scatter(X_pca[:, 0], X_pca[:, 1], c=y, cmap=plt.cm.coolwarm, edgecolors='k')
plt.xlabel('PCA Component 1')
plt.ylabel('PCA Component 2')
plt.title('SVM Decision Boundary (PCA Reduced)')
plt.colorbar()
plt.show()