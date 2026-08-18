import numpy as np
import matplotlib.pyplot as plt
from scipy.cluster.hierarchy import dendrogram, linkage
from scipy.spatial.distance import pdist

plt.rcParams['font.sans-serif'] = ['SimHei']
plt.rcParams['axes.unicode_minus'] = False

X = np.array([
    [0.697,0.460], [0.774,0.376], [0.634,0.264], [0.608,0.318], [0.556,0.215],
    [0.403,0.237], [0.481,0.149], [0.437,0.211], [0.666,0.091], [0.243,0.267],
    [0.245,0.057], [0.343,0.099], [0.639,0.161], [0.657,0.198], [0.360,0.370],
    [0.593,0.042], [0.719,0.103], [0.359,0.188], [0.339,0.241], [0.282,0.257],
    [0.748,0.232], [0.714,0.346], [0.483,0.312], [0.478,0.437], [0.525,0.369],
    [0.751,0.489], [0.532,0.472], [0.473,0.376], [0.725,0.445], [0.446,0.459]
])

dist_matrix = pdist(X, metric='euclidean')
Z = linkage(dist_matrix, method='complete')

fig, ax = plt.subplots(figsize=(10, 6))
dendrogram(
    Z, 
    labels=np.arange(1, len(X) + 1).astype(str),
    ax=ax,
    above_threshold_color='C0'
)

ax.set_ylabel('聚类簇距离')
ax.set_xlabel('样本编号')
ax.set_title('AGNES 算法树状图（采用 d_max）')
ax.axhline(y=0.22, color='black', linestyle='--', alpha=0.8)

plt.tight_layout()
plt.show()