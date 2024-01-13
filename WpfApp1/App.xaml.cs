
using System.Configuration;
using System.Data;
using System.Windows;
using Microsoft.Extensions.Hosting;
using Microsoft.Extensions.Configuration;
using Microsoft.Extensions.DependencyInjection;
using System.Data.SQLite;
using Microsoft.Data.Sqlite;
using Dapper;
using System.IO;
using System.Collections.Generic;

using IHost host = Host.CreateDefaultBuilder(args).Build();

var Configuration = host.Services.GetRequiredService<IConfiguration>();

var cns = Configuration.GetConnectionString("Default");
using var connection = new SqliteConnection("Data Source=test.db");

//var ttt = await connection.QueryAsync("INSERT INTO Users (id, login, pass, email) VALUES (2, 'temp', '1234', 'temp@mail.ru')");
var rows = await connection.QueryAsync("select * from Users");

//Console.WriteLine($"Rows {rows.Count()}");
MessageBox.Show($"Rows {rows.Count()}");
//MessageBox.Show($"Rows {rows}");

IConfiguration Config = new ConfigurationBuilder()
    .SetBasePath(Directory.GetCurrentDirectory())
    .AddJsonFile("appsettings.json")
    .AddEnvironmentVariables()
    .AddCommandLine(args)
    .Build();


namespace WpfApp1
{
    /// <summary>
    /// Interaction logic for App.xaml
    /// </summary>
    public partial class App : Application
    {
    }

}
