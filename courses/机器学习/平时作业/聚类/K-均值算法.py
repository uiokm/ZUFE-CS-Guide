import numpy as np
import matplotlib.pyplot as plt
from sklearn.cluster import KMeans

# --- 环境配置 ---
plt.rcParams['font.sans-serif'] = ['SimHei']
plt.rcParams['axes.unicode_minus'] = False

# --- 数据准备 ---
X = np.array([
    [0.697, 0.460], [0.774, 0.376], [0.634, 0.264], [0.608, 0.318], [0.556, 0.215],
    [0.403, 0.237], [0.481, 0.149], [0.437, 0.211], [0.666, 0.091], [0.243, 0.267],
    [0.245, 0.057], [0.343, 0.099], [0.639, 0.161], [0.657, 0.198], [0.360, 0.370],
    [0.593, 0.042], [0.719, 0.103], [0.359, 0.188], [0.339, 0.241], [0.282, 0.257],
    [0.748, 0.232], [0.714, 0.346], [0.483, 0.312], [0.478, 0.437], [0.525, 0.369],
    [0.751, 0.489], [0.532, 0.472], [0.473, 0.376], [0.725, 0.445], [0.446, 0.459]
])

if __name__ == "__main__":
    k = 3
    
    # 使用 sklearn 的 KMeans 替代手动实现
    # init='random' 对应原代码的随机选择初始化
    # n_init=1 确保只运行一次，与原代码单次迭代逻辑一致
    # random_state=42 保证结果可复现
    clf = KMeans(n_clusters=k, init='random', n_init=1, max_iter=100, random_state=42)
    labels = clf.fit_predict(X)
    centers = clf.cluster_centers_

    # --- 结果打印 ---
    print("最终均值向量：")
    for i, c in enumerate(centers):
        print(f"mu_{i + 1} = {c}")

    # --- 可视化 ---
    colors = ['red', 'blue', 'green']
    markers = ['o', 's', '^']
    plt.figure(figsize=(8, 6))

    for i in range(k):
        cluster_data = X[labels == i]
        plt.scatter(cluster_data[:, 0], cluster_data[:, 1], 
                    c=colors[i], marker=markers[i], label=f'簇 {i + 1}')
    
    plt.scatter(centers[:, 0], centers[:, 1], c='black', marker='*', s=300, label='簇中心')

    plt.xlabel('密度')
    plt.ylabel('含糖率')
    plt.title('K-Means 聚类结果可视化 (Sklearn 实现版)')
    plt.legend()
    plt.grid(True, alpha=0.3)
    plt.show()