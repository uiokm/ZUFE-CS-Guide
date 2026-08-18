import numpy as np

class NeuralNetwork:
    def __init__(self, input_nodes, hidden_nodes, output_nodes, learning_rate):
        # 节点配置
        self.inodes = input_nodes
        self.hnodes = hidden_nodes
        self.onodes = output_nodes
        self.lr = learning_rate

        # 权重初始化 (保持与原代码逻辑一致: -0.5 到 0.5 的均匀分布)
        self.wih = np.random.rand(self.hnodes, self.inodes) - 0.5
        self.who = np.random.rand(self.onodes, self.hnodes) - 0.5

        # 激活函数: Sigmoid
        self.activation = lambda x: 1 / (1 + np.exp(-x))

    def _forward(self, inputs):
        """内部前向传播逻辑，返回中间层和最终层输出"""
        # 隐藏层计算
        hidden_outputs = self.activation(self.wih @ inputs)
        # 输出层计算
        final_outputs = self.activation(self.who @ hidden_outputs)
        return hidden_outputs, final_outputs

    def train(self, inputs_list, targets_list):
        # 转换输入为二维列向量
        inputs = np.array(inputs_list, ndmin=2).T
        targets = np.array(targets_list, ndmin=2).T

        # 前向传播获取输出
        hidden_outputs, final_outputs = self._forward(inputs)

        # 计算误差
        output_errors = targets - final_outputs
        hidden_errors = self.who.T @ output_errors

        # 更新权重: 使用 @ 运算符简化矩阵乘法
        # 公式: ΔW = lr * (E * O * (1 - O)) . T(input)
        self.who += self.lr * ((output_errors * final_outputs * (1.0 - final_outputs)) @ hidden_outputs.T)
        self.wih += self.lr * ((hidden_errors * hidden_outputs * (1.0 - hidden_outputs)) @ inputs.T)

    def query(self, inputs_list):
        # 转换输入
        inputs = np.array(inputs_list, ndmin=2).T
        # 仅获取最终输出
        _, final_outputs = self._forward(inputs)
        return final_outputs

# --- 测试部分 ---
if __name__ == "__main__":
    params = {
        "input_nodes": 3,
        "hidden_nodes": 3,
        "output_nodes": 3,
        "learning_rate": 0.5
    }
    
    test_input = [0.3, 0.7, 0.5]
    target_list = [0.6, 0.4, 0.2]

    # 实例化并运行
    n = NeuralNetwork(**params)
    n.train(test_input, target_list)
    print("预测结果:\n", n.query(test_input))