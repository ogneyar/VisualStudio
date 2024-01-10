
using System.Text;
using System.Collections.ObjectModel;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using System.Xml;
using static System.Net.Mime.MediaTypeNames;


namespace WpfApp1
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {

        private ActionTabViewModal vmd;

        public MainWindow()
        {
            InitializeComponent();

            // Initialize viewModel
            vmd = new ActionTabViewModal();
            // Bind the xaml TabControl to view model tabs
            //tabControl.ItemsSource = vmd.Tabs;
            // Populate the view model tabs
            //vmd.Populate();

            // формируем содержимое вкладки в виде списка
            ListBox notesList = new ListBox();
            notesList.Items.Add("Macbook Pro");
            notesList.Items.Add("HP Pavilion 5478");
            notesList.Items.Add("Acer LK-08");
            // добавление вкладки
            //tabControl.Items.Add(new TabItem
            //{
            //    Header = new TextBlock { Text = "Новая страница" }, // установка заголовка вкладки
            //    Content = notesList // установка содержимого вкладки
            //});
        }
        private void Image_MouseDown(object sender, MouseButtonEventArgs e)
        {
            // This event will be thrown when on a close image clicked
            //vmd.Tabs.RemoveAt(tabControl.SelectedIndex);

            tabControl.Items.Remove(tabControl.SelectedItem);
            MessageBox.Show("text");
        }

        private void MenuItem_Click(object sender, RoutedEventArgs e)
        {
            MenuItem menuItem = (MenuItem)sender;
            MessageBox.Show(menuItem.Header.ToString());
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            string text = textBox1.Text;
            if (text != "")
            {
                MessageBox.Show(text);
            }else
            {
                tabControl.Items.Remove(tabControl.SelectedItem);
            }
        }

        private void CommonClickHandler(object sender, RoutedEventArgs e)
        {
            FrameworkElement feSource = e.Source as FrameworkElement;
            switch (feSource.Name)
            {
                case "YesButton":
                    string messageBoxText = "Do you want to save changes?";
                    string caption = "Word Processor";
                    MessageBoxButton button = MessageBoxButton.YesNoCancel;
                    MessageBoxImage icon = MessageBoxImage.Warning;
                    MessageBoxResult result;

                    result = MessageBox.Show(messageBoxText, caption, button, icon, MessageBoxResult.Yes);
				
				    switch (result)
				    {
					    case MessageBoxResult.Cancel:
						    // User pressed Cancel
						    break;
					    case MessageBoxResult.Yes:
						    // User pressed Yes
						    break;
					    case MessageBoxResult.No:
						    // User pressed No
						    break;
				    }
                    break;
                case "Label":
                    MessageBox.Show("If you close the next window without saving, " + 
                        "your changes will be lost.", "Configuration", MessageBoxButton.OK, MessageBoxImage.Warning);
                    break;
            }
            e.Handled = true;
        }


    }

    // This class will be the Tab int the TabControl
    public class ActionTabItem
    {
        // This will be the text in the tab control
        public string Header { get; set; }
        // This will be the content of the tab control It is a UserControl whits you need to create manualy
        //public UserControl Content { get; set; }
        public string Content { get; set; }
    }

    /// view model for the TabControl To bind on
    public class ActionTabViewModal
    {
        // These Are the tabs that will be bound to the TabControl 
        public ObservableCollection<ActionTabItem> Tabs { get; set; }

        public ActionTabViewModal()
        {
            Tabs = new ObservableCollection<ActionTabItem>();
        }

        public void Populate()
        {
            // Add A tab to TabControl With a specific header and Content(UserControl)
            Tabs.Add(new ActionTabItem { Header = "UserControl 1", Content = "new TestUserControl()" });
            // Add A tab to TabControl With a specific header and Content(UserControl)
            Tabs.Add(new ActionTabItem { Header = "UserControl 2", Content = "new TestUserControl()" });
        }
    }



}