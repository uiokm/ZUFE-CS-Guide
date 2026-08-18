import numpy as np

# 初始化参数 (保持原始数值不变)
W1 = np.array([
    [0.15, 0.25, 0.35],
    [0.22, 0.18, 0.28],
    [0.31, 0.12, 0.21]
])
b1 = np.array([[0.12, 0.08, 0.15]])

W2 = np.array([
    [0.24, 0.16, 0.32],
    [0.19, 0.29, 0.14],
    [0.27, 0.11, 0.23]
])
b2 = np.array([[0.09, 0.13, 0.11]])

def sigmoid(x):
    """Sigmoid 激活函数"""
    return 1 / (1 + np.exp(-x))

def sigmoid_grad(a):
    """基于激活值 a 的 Sigmoid 导数: f'(x) = f(x)(1 - f(x))"""
    return a * (1 - a)

def forward(X):
    """正向传播"""
    # 隐藏层计算
    z1 = np.dot(X, W1) + b1
    a1 = sigmoid(z1)
    # 输出层计算
    z2 = np.dot(a1, W2) + b2
    a2 = sigmoid(z2)
    return a1, a2

def backward(X, y, a1, a2, lr=0.1):
    """反向传播并更新参数"""
    # 声明全局变量以修改外部权重（仅为保持与原逻辑一致）
    global W1, b1, W2, b2
    
    m = X.shape[0]  # 样本数量

    # 1. 计算输出层误差项 (Loss 对 Z2 的偏导)
    # 假设使用 MSE Loss: L = 0.5 * (a2 - y)^2
    # dL/da2 = (a2 - y)
    dz2 = (a2 - y) * sigmoid_grad(a2)
    
    # 2. 计算输出层权重和偏置的梯度
    dw2 = np.dot(a1.T, dz2)
    db2 = np.sum(dz2, axis=0, keepdims=True)

    # 3. 计算隐藏层误差项 (Loss 对 Z1 的偏导)
    da1 = np.dot(dz2, W2.T)
    dz1 = da1 * sigmoid_grad(a1)
    
    # 4. 计算隐藏层权重和偏置的梯度
    dw1 = np.dot(X.T, dz1)
    db1 = np.sum(dz1, axis=0, keepdims=True)

    # 5. 参数更新 (梯度下降)
    W2 -= lr * dw2
    b2 -= lr * db2
    W1 -= lr * dw1
    b1 -= lr * db1

def predict(X):
    """预测函数"""
    _, y_pred = forward(X)
    return y_pred

if __name__ == "__main__":
    # 输入与标签
    X_input = np.array([[0.3, 0.7, 0.5]])
    y_true = np.array([[0.6, 0.4, 0.2]])

    print(f"初始输入:\n{X_input}")

    # 执行一次迭代
    hidden_out, final_out = forward(X_input)
    
    print("\n--- 正向传播结果 ---")
    print(f"隐藏层输出 (A1):\n{hidden_out.round(4)}")
    print(f"输出层结果 (A2):\n{final_out.round(4)}")

    # 更新权重
    backward(X_input, y_true, hidden_out, final_out)

    print("\n--- 更新权重后的预测结果 ---")
    prediction = predict(X_input)
    print(f"最终预测:\n{prediction.round(4)}")