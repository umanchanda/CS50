import cs50
import csv
from flask import Flask, jsonify, redirect, render_template, request

# Configure application
app = Flask(__name__)

# Reload templates when they are changed
app.config["TEMPLATES_AUTO_RELOAD"] = True


@app.after_request
def after_request(response):
    """Disable caching"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/", methods=["GET"])
def get_index():
    return redirect("/form")


@app.route("/form", methods=["GET"])
def get_form():
    return render_template("form.html")


@app.route("/form", methods=["POST"])
def post_form():
    name = request.form.get("name")
    house = request.form.get("house")
    position = request.form.get("position")

    with open('survey.csv', 'a') as csvfile:
        survey = csv.writer(csvfile)
        survey.writerow([name, house, position])
    return redirect("/sheet")


@app.route("/sheet", methods=["GET"])
def get_sheet():
    with open('survey.csv', 'r') as csvfile:
        c = csv.reader(csvfile)
        responses = list(c)
    return render_template("sheet.html", responses=responses)
