from flask import Flask, render_template, request

app = Flask(__name__)

# JINJA -> sintax {{}} %%

# default: methods=["GET"]
@app.route("/", methods=["GET", "POST"])
def index():
    # return "hello, world"
    # ./templates/index.html is already set
    if request.method == "GET":
        return render_template("index.html")
    if request.method == "POST":
        return render_template("greet.html", name=request.form.get("name", "world"))

"""
# @app.route("/greet")
@app.route("/greet", methods=["POST"])
def greet():
    # 'name' is the get parameter, so it can be any name as long as it changes in the other files
    # TO GET: request.args.get // TO POST: request.form.get
    # return render_template("greet.html", name=request.args.get("name", "world"))
    return render_template("greet.html", name=request.form.get("name", "world"))
"""
