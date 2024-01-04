using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApp1
{
    public partial class MainForm : Form
    {
        public MainForm()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {

            AlertForm form = new AlertForm();

            //form.StartPosition = FormStartPosition.Manual;
            //form.Location = new Point(this.Width / 2 - form.Width / 2 + this.Location.X,
            //                        this.Height / 2 - form.Height / 2 + this.Location.Y);
            form.Show();

        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void tabPage2_Click(object sender, EventArgs e)
        {

        }

        private void button_add_tabcontrol_Click(object sender, EventArgs e)
        {
            TabPage tabPage1 = new TabPage();
            tabPage1.Name = "tabPage2";
            tabPage1.Text = "NewPage";
            tabPage1.BackColor = Color.Green;
            tabPage1.ForeColor = Color.White;
            tabPage1.Font = new Font("Verdana", 12);
            tabPage1.Width = 100;
            tabPage1.Height = 100;

            Button button1 = new Button
            {
                Name = "button_new",
                Text = "Click Me",
                BackColor = Color.Blue,
                ForeColor = Color.White,
                Font = new Font("Verdana", 12),
                Width = 100,
                Height = 30,
                Location = new Point(50, 10)
            };

            tabPage1.Controls.Add(button1);

            tabControl.TabPages.Add(tabPage1);
        }
    }
}
