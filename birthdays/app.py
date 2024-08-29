from flask import Flask, render_template, request, redirect
import sqlite3

app = Flask(__name__)

DATABASE = 'birthdays.db'


def get_db_connection():
    conn = sqlite3.connect(DATABASE)
    conn.row_factory = sqlite3.Row
    return conn


@app.route('/', methods=['GET', 'POST'])
def index():
    if request.method == 'POST':
        # Get form data
        name = request.form['name']
        month = int(request.form['month'])
        day = int(request.form['day'])

        # Insert new birthday into database
        conn = get_db_connection()
        conn.execute('INSERT INTO birthdays (name, month, day) VALUES (?, ?, ?)',
                     (name, month, day))
        conn.commit()
        conn.close()

        return redirect('/')

    # Handle GET request
    conn = get_db_connection()
    birthdays = conn.execute('SELECT * FROM birthdays').fetchall()
    conn.close()
    return render_template('index.html', birthdays=birthdays)


if __name__ == '__main__':
    app.run(debug=True)
