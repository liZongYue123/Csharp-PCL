namespace SegDemo
{
    partial class SegDemo
    {
        /// <summary>
        /// 必需的设计器变量。
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 清理所有正在使用的资源。
        /// </summary>
        /// <param name="disposing">如果应释放托管资源，为 true；否则为 false。</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows 窗体设计器生成的代码

        /// <summary>
        /// 设计器支持所需的方法 - 不要修改
        /// 使用代码编辑器修改此方法的内容。
        /// </summary>
        private void InitializeComponent()
        {
            this.panel1 = new System.Windows.Forms.Panel();
            this.panel2 = new System.Windows.Forms.Panel();
            this.loadButton = new System.Windows.Forms.Button();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.eucClusterButton = new System.Windows.Forms.Button();
            this.disThreshTextBox = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.regionGrowButton = new System.Windows.Forms.Button();
            this.smoothTextBox = new System.Windows.Forms.TextBox();
            this.label4 = new System.Windows.Forms.Label();
            this.curveTextBox = new System.Windows.Forms.TextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.neighborTextBox = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.groupBox1.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.SuspendLayout();
            // 
            // panel1
            // 
            this.panel1.Location = new System.Drawing.Point(9, 0);
            this.panel1.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(415, 386);
            this.panel1.TabIndex = 0;
            // 
            // panel2
            // 
            this.panel2.Location = new System.Drawing.Point(431, 0);
            this.panel2.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.panel2.Name = "panel2";
            this.panel2.Size = new System.Drawing.Size(412, 386);
            this.panel2.TabIndex = 0;
            // 
            // loadButton
            // 
            this.loadButton.Location = new System.Drawing.Point(123, 431);
            this.loadButton.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.loadButton.Name = "loadButton";
            this.loadButton.Size = new System.Drawing.Size(89, 38);
            this.loadButton.TabIndex = 0;
            this.loadButton.Text = "点击生成点云";
            this.loadButton.UseVisualStyleBackColor = true;
            this.loadButton.Click += new System.EventHandler(this.loadButton_Click);
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.eucClusterButton);
            this.groupBox1.Controls.Add(this.disThreshTextBox);
            this.groupBox1.Controls.Add(this.label1);
            this.groupBox1.Location = new System.Drawing.Point(326, 390);
            this.groupBox1.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Padding = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.groupBox1.Size = new System.Drawing.Size(146, 115);
            this.groupBox1.TabIndex = 0;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "groupBox1";
            // 
            // eucClusterButton
            // 
            this.eucClusterButton.Location = new System.Drawing.Point(14, 22);
            this.eucClusterButton.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.eucClusterButton.Name = "eucClusterButton";
            this.eucClusterButton.Size = new System.Drawing.Size(63, 36);
            this.eucClusterButton.TabIndex = 3;
            this.eucClusterButton.Text = "欧式聚类";
            this.eucClusterButton.UseVisualStyleBackColor = true;
            this.eucClusterButton.Click += new System.EventHandler(this.eucClusterButton_Click);
            // 
            // disThreshTextBox
            // 
            this.disThreshTextBox.Location = new System.Drawing.Point(67, 74);
            this.disThreshTextBox.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.disThreshTextBox.Name = "disThreshTextBox";
            this.disThreshTextBox.Size = new System.Drawing.Size(59, 21);
            this.disThreshTextBox.TabIndex = 2;
            this.disThreshTextBox.Text = "5";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(12, 76);
            this.label1.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(65, 12);
            this.label1.TabIndex = 1;
            this.label1.Text = "距离阈值：";
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.regionGrowButton);
            this.groupBox2.Controls.Add(this.smoothTextBox);
            this.groupBox2.Controls.Add(this.label4);
            this.groupBox2.Controls.Add(this.curveTextBox);
            this.groupBox2.Controls.Add(this.label3);
            this.groupBox2.Controls.Add(this.neighborTextBox);
            this.groupBox2.Controls.Add(this.label2);
            this.groupBox2.Location = new System.Drawing.Point(476, 390);
            this.groupBox2.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Padding = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.groupBox2.Size = new System.Drawing.Size(244, 115);
            this.groupBox2.TabIndex = 0;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "groupBox1";
            // 
            // regionGrowButton
            // 
            this.regionGrowButton.Location = new System.Drawing.Point(6, 22);
            this.regionGrowButton.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.regionGrowButton.Name = "regionGrowButton";
            this.regionGrowButton.Size = new System.Drawing.Size(67, 36);
            this.regionGrowButton.TabIndex = 3;
            this.regionGrowButton.Text = "区域生长";
            this.regionGrowButton.UseVisualStyleBackColor = true;
            this.regionGrowButton.Click += new System.EventHandler(this.regionGrowButton_Click);
            // 
            // smoothTextBox
            // 
            this.smoothTextBox.Location = new System.Drawing.Point(164, 30);
            this.smoothTextBox.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.smoothTextBox.Name = "smoothTextBox";
            this.smoothTextBox.Size = new System.Drawing.Size(59, 21);
            this.smoothTextBox.TabIndex = 2;
            this.smoothTextBox.Text = "4";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(98, 33);
            this.label4.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(77, 12);
            this.label4.TabIndex = 1;
            this.label4.Text = "平滑度阈值：";
            // 
            // curveTextBox
            // 
            this.curveTextBox.Location = new System.Drawing.Point(179, 74);
            this.curveTextBox.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.curveTextBox.Name = "curveTextBox";
            this.curveTextBox.Size = new System.Drawing.Size(59, 21);
            this.curveTextBox.TabIndex = 2;
            this.curveTextBox.Text = "3";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(124, 76);
            this.label3.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(65, 12);
            this.label3.TabIndex = 1;
            this.label3.Text = "曲率阈值：";
            // 
            // neighborTextBox
            // 
            this.neighborTextBox.Location = new System.Drawing.Point(59, 74);
            this.neighborTextBox.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.neighborTextBox.Name = "neighborTextBox";
            this.neighborTextBox.Size = new System.Drawing.Size(59, 21);
            this.neighborTextBox.TabIndex = 2;
            this.neighborTextBox.Text = "67";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(12, 76);
            this.label2.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(53, 12);
            this.label2.TabIndex = 1;
            this.label2.Text = "近邻数：";
            // 
            // SegDemo
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(845, 515);
            this.Controls.Add(this.groupBox2);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.loadButton);
            this.Controls.Add(this.panel2);
            this.Controls.Add(this.panel1);
            this.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.Name = "SegDemo";
            this.Text = "Form1";
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.Panel panel2;
        private System.Windows.Forms.Button loadButton;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox disThreshTextBox;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.TextBox neighborTextBox;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox smoothTextBox;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.TextBox curveTextBox;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Button eucClusterButton;
        private System.Windows.Forms.Button regionGrowButton;
    }
}

