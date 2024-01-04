namespace WindowsFormsApp1
{
    partial class MainForm
    {
        /// <summary>
        /// Обязательная переменная конструктора.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Освободить все используемые ресурсы.
        /// </summary>
        /// <param name="disposing">истинно, если управляемый ресурс должен быть удален; иначе ложно.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Код, автоматически созданный конструктором форм Windows

        /// <summary>
        /// Требуемый метод для поддержки конструктора — не изменяйте 
        /// содержимое этого метода с помощью редактора кода.
        /// </summary>
        private void InitializeComponent()
        {
            this.button_get_alert = new System.Windows.Forms.Button();
            this.checkBox_ = new System.Windows.Forms.CheckBox();
            this.label_for_checkbox = new System.Windows.Forms.Label();
            this.tableLayoutPanel1 = new System.Windows.Forms.TableLayoutPanel();
            this.treeView1 = new System.Windows.Forms.TreeView();
            this.trackBar1 = new System.Windows.Forms.TrackBar();
            this.vScrollBar1 = new System.Windows.Forms.VScrollBar();
            this.tabControl = new System.Windows.Forms.TabControl();
            this.tabPage1 = new System.Windows.Forms.TabPage();
            this.button_add_tabcontrol = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.trackBar1)).BeginInit();
            this.tabControl.SuspendLayout();
            this.SuspendLayout();
            // 
            // button_get_alert
            // 
            this.button_get_alert.Location = new System.Drawing.Point(49, 59);
            this.button_get_alert.Name = "button_get_alert";
            this.button_get_alert.Size = new System.Drawing.Size(185, 23);
            this.button_get_alert.TabIndex = 0;
            this.button_get_alert.Text = "Показать уведомление";
            this.button_get_alert.UseVisualStyleBackColor = true;
            this.button_get_alert.Click += new System.EventHandler(this.button1_Click);
            // 
            // checkBox_
            // 
            this.checkBox_.AutoSize = true;
            this.checkBox_.Location = new System.Drawing.Point(171, 28);
            this.checkBox_.Name = "checkBox_";
            this.checkBox_.Size = new System.Drawing.Size(62, 17);
            this.checkBox_.TabIndex = 1;
            this.checkBox_.Text = "Пустая";
            this.checkBox_.UseVisualStyleBackColor = true;
            // 
            // label_for_checkbox
            // 
            this.label_for_checkbox.AutoSize = true;
            this.label_for_checkbox.Location = new System.Drawing.Point(61, 28);
            this.label_for_checkbox.Name = "label_for_checkbox";
            this.label_for_checkbox.Size = new System.Drawing.Size(87, 13);
            this.label_for_checkbox.TabIndex = 2;
            this.label_for_checkbox.Text = "Выбрать форму";
            this.label_for_checkbox.Click += new System.EventHandler(this.label1_Click);
            // 
            // tableLayoutPanel1
            // 
            this.tableLayoutPanel1.ColumnCount = 3;
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 24.35897F));
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 75.64103F));
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Absolute, 68F));
            this.tableLayoutPanel1.Location = new System.Drawing.Point(12, 434);
            this.tableLayoutPanel1.Name = "tableLayoutPanel1";
            this.tableLayoutPanel1.RowCount = 2;
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 50F));
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 50F));
            this.tableLayoutPanel1.Size = new System.Drawing.Size(259, 58);
            this.tableLayoutPanel1.TabIndex = 3;
            // 
            // treeView1
            // 
            this.treeView1.Location = new System.Drawing.Point(277, 12);
            this.treeView1.Name = "treeView1";
            this.treeView1.Size = new System.Drawing.Size(121, 56);
            this.treeView1.TabIndex = 4;
            // 
            // trackBar1
            // 
            this.trackBar1.Location = new System.Drawing.Point(277, 74);
            this.trackBar1.Name = "trackBar1";
            this.trackBar1.Size = new System.Drawing.Size(121, 45);
            this.trackBar1.TabIndex = 5;
            // 
            // vScrollBar1
            // 
            this.vScrollBar1.Location = new System.Drawing.Point(796, 0);
            this.vScrollBar1.Name = "vScrollBar1";
            this.vScrollBar1.Size = new System.Drawing.Size(17, 502);
            this.vScrollBar1.TabIndex = 6;
            // 
            // tabControl
            // 
            this.tabControl.Controls.Add(this.tabPage1);
            this.tabControl.Location = new System.Drawing.Point(12, 88);
            this.tabControl.Name = "tabControl";
            this.tabControl.SelectedIndex = 0;
            this.tabControl.Size = new System.Drawing.Size(247, 100);
            this.tabControl.TabIndex = 7;
            // 
            // tabPage1
            // 
            this.tabPage1.Location = new System.Drawing.Point(4, 22);
            this.tabPage1.Name = "tabPage1";
            this.tabPage1.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage1.Size = new System.Drawing.Size(239, 74);
            this.tabPage1.TabIndex = 2;
            this.tabPage1.Text = "tabPage1";
            this.tabPage1.UseVisualStyleBackColor = true;
            // 
            // button_add_tabcontrol
            // 
            this.button_add_tabcontrol.Location = new System.Drawing.Point(95, 194);
            this.button_add_tabcontrol.Name = "button_add_tabcontrol";
            this.button_add_tabcontrol.Size = new System.Drawing.Size(75, 23);
            this.button_add_tabcontrol.TabIndex = 8;
            this.button_add_tabcontrol.Text = "Добавить";
            this.button_add_tabcontrol.UseVisualStyleBackColor = true;
            this.button_add_tabcontrol.Click += new System.EventHandler(this.button_add_tabcontrol_Click);
            // 
            // MainForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(814, 504);
            this.Controls.Add(this.button_add_tabcontrol);
            this.Controls.Add(this.tabControl);
            this.Controls.Add(this.vScrollBar1);
            this.Controls.Add(this.trackBar1);
            this.Controls.Add(this.treeView1);
            this.Controls.Add(this.tableLayoutPanel1);
            this.Controls.Add(this.label_for_checkbox);
            this.Controls.Add(this.checkBox_);
            this.Controls.Add(this.button_get_alert);
            this.Name = "MainForm";
            this.Text = "Я вас приветствую!";
            ((System.ComponentModel.ISupportInitialize)(this.trackBar1)).EndInit();
            this.tabControl.ResumeLayout(false);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button button_get_alert;
        private System.Windows.Forms.CheckBox checkBox_;
        private System.Windows.Forms.Label label_for_checkbox;
        private System.Windows.Forms.TableLayoutPanel tableLayoutPanel1;
        private System.Windows.Forms.TreeView treeView1;
        private System.Windows.Forms.TrackBar trackBar1;
        private System.Windows.Forms.VScrollBar vScrollBar1;
        private System.Windows.Forms.TabControl tabControl;
        private System.Windows.Forms.TabPage tabPage1;
        private System.Windows.Forms.Button button_add_tabcontrol;
    }
}

