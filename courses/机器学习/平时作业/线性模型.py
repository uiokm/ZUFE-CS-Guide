import numpy as np
import matplotlib.pyplot as plt
from matplotlib import rcParams


rcParams['font.sans-serif'] = ['SimHei']  
rcParams['axes.unicode_minus'] = False    

def calculate_linear_regression(x_data, y_data):
    """Calculates regression coefficients beta_0 and beta_1."""
    x_mean = np.mean(x_data)
    y_mean = np.mean(y_data)
    
    
    numerator = np.sum((x_data - x_mean) * (y_data - y_mean))
    denominator = np.sum((x_data - x_mean)**2)
    
    b1 = numerator / denominator
    b0 = y_mean - b1 * x_mean
    
    return b0, b1


X_train = np.array([77.36, 116.74, 116.7, 100.68, 116.1, 115.81, 104.24, 106.73, 115.86])
Y_train = np.array([470, 730, 760, 680, 700, 720, 700, 690, 730])
X_predict = np.array([56.6, 78.4, 58, 123.5, 56.8, 77, 150.6])


beta_0, beta_1 = calculate_linear_regression(X_train, Y_train)
Y_predict = beta_0 + beta_1 * X_predict


print(f"回归方程: 价格 = {beta_0:.4f} + {beta_1:.4f} * 面积")

plt.figure(figsize=(10, 6))


plt.scatter(X_train, Y_train, color='blue', label="训练数据 (Actual)", zorder=5)


line_x = np.linspace(min(X_train.min(), X_predict.min()), max(X_train.max(), X_predict.max()), 100)
line_y = beta_0 + beta_1 * line_x
plt.plot(line_x, line_y, color='red', linestyle='--', label="回归直线 (Model)")


plt.scatter(X_predict, Y_predict, color='green', marker='x', s=100, label="预测点 (Predicted)")

plt.xlabel("面积 (平方米)")
plt.ylabel("价格 (万元)")
plt.title("房屋面积与价格线性回归分析")
plt.grid(True, linestyle=':', alpha=0.6)
plt.legend()
plt.show()