from cs50 import SQL
from flask import Flask, redirect, render_template, request
from flask_mail import Mail, Message
import os

app = Flask(__name__)
# configuracoes de email
app.config["MAIL_DAFAULT_SENDER"] = os.getenv("MAIL_DEFAULT_SENDER")
app.config["MAIL_PASSWORD"] = os.getenv("MAIL_PASSWORD")
app.config["MAIL_PORT"] = 587
app.config["MAIL_SERVER"] = "smtp.gmail.com"
app.config["MAIL_USE_TLS"] = True
app.config["MAIL_USERNAME"] = os.getenv("MAIL_USERNAME")
mail = Mail(app)

# db = SQL("sqlite:///froshims.db")

REGISTRANTS = {}

SPORTS = [
    "Dodgeball",
    "Flag Football",
    "Soccer",
    "Volleyball",
    "Ultimate Frisbee"
]

@app.route("/")
def index():
    return render_template("index.html", sports=SPORTS)

@app.route("/register", methods=["POST"])
def register():
    # if not request.form.get("name") or request.form.get("sport") not in SPORTS:
    #    return render_template("failure.html")
    # return render_template("success.html")
    email = request.form.get("email")
    if not email:
        return render_template("error.html", message="Missing Email")

    sport = request.form.get("sport")
    if not sport:
        return render_template("error.html", message="Missing Sport")

    if sport not in SPORTS:
        return render_template("error.html", message="Invalid Sport")

    # REGISTRANTS[name] = sport

    # db.execute("INSERT INTO registrants (name, sport) VALUES(?, ?)", name, sport)

    message = Message("You are registered!", recipients=[email])
    mail.send(message)

    # return render_template("success.html")
    # return redirect("/registrants")
    return render_template("success.html")


# @app.route("/registrants")
# def registrants():
#    registrants = db.execute("SELECT * FROM registrants")
#    return render_template("registrants.html", registrants=registrants)
