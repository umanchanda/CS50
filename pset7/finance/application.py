from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.exceptions import default_exceptions
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Ensure responses aren't cached
@app.after_request
def after_request(response):
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_FILE_DIR"] = mkdtemp()
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""
    return apology("TODO", 400)


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    if request.method == "POST":

        stock = lookup(request.form.get("symbol").upper())
        if not stock:
            return apology("Stock not found", 400)

        try:
            shares_bought = int(request.form.get("shares"))
            if shares_bought < 0:
                return apology("Invalid number of shares", 400)
        except:
            return apology("Invalid number of shares", 400)

        money = db.execute("SELECT cash FROM users WHERE id=:id", id=session["user_id"])
        money_available = money[0]["cash"]
        stock_price = lookup(request.form.get("symbol").upper())["price"]

        money_left = money_available - shares_bought * stock_price

        if money_left < 0:
            return apology("Invalid Funds", 400)

        db.execute("UPDATE users SET cash=:cash WHERE id=:id", cash=money_left, id=session["user_id"])
        db.execute("INSERT INTO histories (symbol, shares, price, id) VALUES (:symbol, :shares, :price, :id)", symbol=stock["symbol"], shares=shares_bought, price=stock_price, id=session["user_id"])

        num_shares = db.execute("SELECT shares FROM histories WHERE id=:id AND symbol=:symbol", id=session["user_id"], symbol=stock["symbol"])

        if not num_shares:
            portfolio = db.execute("INSERT INTO portfolio (id, symbol, shares, price, total) VALUES (:id, :symbol, :shares, :price, :total)", id=session["user_id"], symbol=stock["symbol"], shares=str(shares_bought), price=stock_price, total=shares_bought * stock_price)
        else:
            new_shares = str(int(num_shares[0]["shares"]) + shares_bought)
            db.execute("UPDATE portfolio SET shares=:shares WHERE id=:id AND symbol=:symbol", shares=str(new_shares), id=session["user_id"], symbol=stock["symbol"])

        return render_template("index.html")
    else:
        return render_template("buy.html")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""

    return apology("TODO")


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = :username", username=request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""
    if request.method == "POST":
        stock = lookup(request.form.get("symbol").upper())
        if not stock:
            return apology("Stock not found")

        return render_template("quoted.html", stock=stock)
    else:
        return render_template("quote.html")

@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""

    # forget any user id
    session.clear()

    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 400)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 400)

        # Ensure passwords match
        elif request.form.get("password") != request.form.get("confirmation"):
            return apology("passwords do not match", 400)

        hashed_passwd = generate_password_hash(request.form.get("password"))

        check_username = db.execute("SELECT * FROM users WHERE username = :username", username=request.form.get("username"))
        if len(check_username) != 0:
            return apology("username already exists", 400)

        insert = db.execute("INSERT INTO users (username, hash) VALUES (:username, :hash)", username=request.form.get("username"), hash=hashed_passwd)

        session["user_id"] = insert

        return redirect("/")
    else:
        return render_template("register.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    return render_template("sell.html")


def errorhandler(e):
    """Handle error"""
    return apology(e.name, e.code)


# listen for errors
for code in default_exceptions:
    app.errorhandler(code)(errorhandler)
